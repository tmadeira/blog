import * as React from "react";
import { Link } from "gatsby";
import { PlasmicLayout } from "./plasmic/site_layout/PlasmicLayout";

import "./Layout.scss";

import MenuItem from "./MenuItem";

export default function Layout(props) {
  return (
    <PlasmicLayout
      {...props}
      header={{
        style: { position: "fixed" },
      }}
      title={<Link to="/">Tiago Madeira</Link>}
      menu={
        <>
          <MenuItem to="/blog">Blog</MenuItem>
          <MenuItem to="/cv">CV</MenuItem>
        </>
      }
    />
  );
}
