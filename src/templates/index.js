import React from "react";
import { graphql } from "gatsby";

import Article from "../components/Article";
import Head from "../components/Head";
import Layout from "../components/Layout";
import Pagination from "../components/Pagination";

export default function ({ data, pageContext }) {
  let title = "Blog";
  if (pageContext.humanPageNumber !== 1) {
    title += ` (página ${pageContext.humanPageNumber})`;
  }

  return (
    <Layout>
      <Head title={title} />

      {data.allMarkdownRemark.edges.map((edge, key) => (
        <Article key={key} post={edge.node} />
      ))}

      <Pagination ctx={pageContext} />
    </Layout>
  );
}

export const pageQuery = graphql`
  query($skip: Int!, $limit: Int!) {
    allMarkdownRemark(
      sort: { fields: frontmatter___date, order: DESC }
      skip: $skip
      limit: $limit
    ) {
      edges {
        node {
          frontmatter {
            url
            title
            date
            tags
          }
          html
        }
      }
    }
  }
`;
