import * as React from "react";
import { Link } from "gatsby";
import { PlasmicPagination } from "./plasmic/site_layout/PlasmicPagination";

function Pagination({ ctx }) {
  return (
    <PlasmicPagination
      prev={
        ctx.previousPagePath ? (
          {
            as: Link,
            props: {
              to: ctx.previousPagePath,
            },
          }
        ) : (
          <></>
        )
      }
      next={
        ctx.nextPagePath ? (
          {
            as: Link,
            props: {
              to: ctx.nextPagePath,
            },
          }
        ) : (
          <></>
        )
      }
    />
  );
}

export default Pagination;
