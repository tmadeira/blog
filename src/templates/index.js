import React from "react";
import { graphql } from "gatsby";

import Article from "../components/Article";
import Head from "../components/Head";
import Layout from "../components/Layout";
import Pagination from "../components/Pagination";

export default function ({ data, pageContext }) {
  return (
    <Layout>
      <Head title="Blog" />

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
