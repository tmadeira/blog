import matter from 'gray-matter';

export async function getAllPosts() {
  const context = require.context('../posts', true, /\.md$/);

  const posts = [];
  for (const key of context.keys()) {
    const name = key.replace(/^.*[\\\/]/, '').slice(0, -3);
    const [year, month, ...parts] = name.split('-');
    const slug = parts.join('-');
    const url = `/${year}/${month}/${slug}`;

    const content = await import(`../posts/${key.slice(2)}`);
    const md = matter(content.default);

    posts.push({
      url,
      ...md.data,
    });
  }

  return posts;
};
