import matter from 'gray-matter';

import Markdown from '@components/Markdown';

export default function Post({data, content}) {
  return (
    <Markdown content={content} />
  );
};

export async function getStaticProps({...ctx}) {
  const {year, month, slug} = ctx.params;

  const content = await import(`../../../posts/${year}-${month}-${slug}.md`);
  const md = matter(content.default);

  // NextJS can not serialize date objects.
  if (Object.prototype.toString.call(md.data.date) === "[object Date]") {
    md.data.date = md.data.date.toISOString();
  }

  return {
    props: {
      data: md.data,
      content: md.content,
    },
  };
};

export async function getStaticPaths() {
  const context = require.context('../../../posts', true, /\.md$/);

  const paths = [];
  for (const key of context.keys()) {
    const path = key.replace(/^.*[\\\/]/, '').slice(0, -3);
    const [year, month, ...parts] = path.split('-');
    const slug = parts.join('-');
    paths.push(`/${year}/${month}/${slug}`);
  }

  return {
    paths,
    fallback: false,
  };
};
