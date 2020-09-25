import matter from 'gray-matter';

export async function getPost(path) {
  const content = await import(`../posts/${path}`);
  const md = matter(content.default);

  // NextJS can not serialize date objects.
  if (Object.prototype.toString.call(md.data.date) === "[object Date]") {
    md.data.date = md.data.date.toISOString();
  }

  const name = path.slice(0, -3);
  const [year, month, ...parts] = name.split('-');
  const slug = parts.join('-');
  const uri = `/${year}/${month}/${slug}`;

  return {
    data: md.data,
    content: md.content,
    uri,
  };
}

export async function getAllPosts() {
  const context = require.context('../posts', true, /\.md$/);

  const posts = [];
  for (const key of context.keys()) {
    const post = await getPost(key.slice(2));
    posts.push(post);
  }

  return posts;
};
