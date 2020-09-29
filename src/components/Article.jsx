import * as React from "react";
import {Link} from 'gatsby';
import { PlasmicArticle } from "./plasmic/site_layout/PlasmicArticle";

import 'katex/dist/katex.min.css';

import Badge from './Badge';

const months = ['janeiro', 'fevereiro', 'março', 'abril', 'maio', 'junho', 'julho', 'agosto', 'setembro', 'outubro', 'novembro', 'dezembro'];

function Article({post}) {
  const date = new Date(post.frontmatter.date);

  const day = date.getDate();
  const month = months[date.getMonth()];
  const year = date.getFullYear();

  const fmtDate = `${day} de ${month} de ${year}`;

  return (
    <PlasmicArticle
      title={<Link style={{textDecoration: 'none'}} to={post.frontmatter.url}>{post.frontmatter.title}</Link>}
      date={fmtDate}
      tags={<>
        {post.frontmatter.tags.map((tag, key) =>
          <Badge key={key}>{tag}</Badge>
        )}
      </>}
    >
      <div className="entry" dangerouslySetInnerHTML={{__html: post.html}} />
    </PlasmicArticle>
  );
}

export default Article;
