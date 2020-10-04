const slugify = require("slugify");
const { paginate } = require("gatsby-awesome-pagination");

exports.createPages = async ({ actions, graphql, reporter }) => {
  const { createPage } = actions;

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

      tags: allMarkdownRemark {
        group(field: frontmatter___tags) {
          fieldValue
          edges {
            node {
              frontmatter {
                url
              }
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

  // Single pages.
  const tpl = require.resolve(`./src/templates/single.js`);
  result.data.allPosts.edges.forEach(({ node }) => {
    createPage({
      path: node.frontmatter.url,
      component: tpl,
      context: {
        url: node.frontmatter.url,
      },
    });
  });

  // Blog (index).
  paginate({
    createPage,
    items: result.data.allPosts.edges.map(({ node }) => node),
    itemsPerPage: 5,
    pathPrefix: "/blog",
    component: require.resolve(`./src/templates/index.js`),
  });

  // Tags.
  result.data.tags.group.forEach((tag) => {
    const slug = slugify(tag.fieldValue);
    paginate({
      createPage,
      items: tag.edges.map(({ node }) => node),
      itemsPerPage: 5,
      pathPrefix: `/tags/${slug}`,
      component: require.resolve(`./src/templates/tag.js`),
      context: {
        tag: tag.fieldValue,
      },
    });
  });
};
