import matter from 'gray-matter';

import Markdown from '@components/Markdown';
import {getPost} from '@api';

export default function Post({data, content}) {
  return (
    <Markdown content={content} />
  );
};

export async function getStaticProps({...ctx}) {
  const {year, month, slug} = ctx.params;
  const post = await getPost(`${year}-${month}-${slug}.md`);

  return {
    props: post,
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
