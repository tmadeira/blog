const { paginate } = require("gatsby-awesome-pagination");

exports.createPages = async ({ actions, graphql, reporter }) => {
  const { createPage } = actions;

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
  `);

  if (result.errors) {
    reporter.panicOnBuild(`Error while running GraphQL query.`);
    return;
  }

  result.data.allPosts.edges.forEach(({ node }) => {
    createPage({
      path: node.frontmatter.url,
      component: tpl,
      context: {
        url: node.frontmatter.url,
      },
    });
  });

  paginate({
    createPage,
    items: result.data.allPosts.edges.map(({ node }) => node),
    itemsPerPage: 5,
    pathPrefix: "/blog",
    component: require.resolve(`./src/templates/index.js`),
  });
};
