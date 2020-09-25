import {getAllPosts} from '@api';

export default function Blog({posts}) {
  console.log(posts);
  return <>TODO</>;
};

export async function getStaticProps() {
  let posts = await getAllPosts();
  posts = posts.slice(0, 10);

  for (var i = 0; i < posts.length; i++) {
    // NextJS can not serialize date objects.
    if (Object.prototype.toString.call(posts[i].date) === "[object Date]") {
      posts[i].date = posts[i].date.toISOString();
    }
  }

  return {
    props: {
      posts,
    },
  };
}
