exports.createPages = async ({actions, graphql, reporter}) => {
  const {createPage} = actions;

  const tpl = require.resolve(`./src/templates/single.js`);
  const result = await graphql(`
    {
      allPosts: allMarkdownRemark {
        edges {
          node {
            frontmatter {
              url
            }
          }
        }
      }
    }
  `)

  if (result.errors) {
    reporter.panicOnBuild(`Error while running GraphQL query.`);
    return;
  }

  result.data.allPosts.edges.forEach(({node}) => {
    createPage({
      path: node.frontmatter.url,
      component: tpl,
      context: {
        url: node.frontmatter.url,
      },
    })
  });
}