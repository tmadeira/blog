import matter from 'gray-matter';

import Markdown from '../../../components/Markdown';

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
  const params = ((context) => {
    return context.keys().map((key, index) => {
      const path = key.replace(/^.*[\\\/]/, '').slice(0, -3);
      const [year, month, ...parts] = path.split('-');
      const slug = parts.join('-');
      return {year, month, slug};
    });
  })(require.context('../../../posts', true, /\.md$/));

  const paths = params.map(({year, month, slug}) => `/${year}/${month}/${slug}`);

  return {
    paths,
    fallback: false,
  };
};
