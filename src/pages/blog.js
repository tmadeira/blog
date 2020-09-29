import React from "react";
import { graphql } from "gatsby";

import Article from "../components/Article";
import Head from "../components/Head";
import Layout from "../components/Layout";

export default function ({ data }) {
  return (
    <Layout>
      <Head title="Blog" />

      {data.allMarkdownRemark.edges.map((edge, key) => (
        <Article key={key} post={edge.node} />
      ))}
    </Layout>
  );
}

export const pageQuery = graphql`
  {
    allMarkdownRemark(
      limit: 5
      sort: { fields: frontmatter___date, order: DESC }
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
