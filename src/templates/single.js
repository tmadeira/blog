import React from 'react';
import {graphql} from 'gatsby';

import Article from '../components/Article';
import Comments from '../components/Comments';
import Head from '../components/Head';
import Layout from '../components/Layout';

export default function Single({data}) {
  return (
    <Layout>
      <Head />

      <Article post={data.markdownRemark} />

      <Comments />
    </Layout>
  );
};

export const pageQuery = graphql`
  query($url: String!) {
    markdownRemark(frontmatter: {url: {eq: $url}}) {
      frontmatter {
        url
        title
        date
        tags
      }
      html
    }
  }
`;
