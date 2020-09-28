import * as React from 'react';
import { PlasmicLayout } from "./plasmic/site_layout/PlasmicLayout";

import './Layout.scss';

import MenuItem from "./MenuItem";

function Layout(props) {
  return <PlasmicLayout
    {...props}

    header={{
      style: {position: 'fixed'},
    }}

    title="Tiago Madeira"

    menuItem1={<MenuItem to="/">About</MenuItem>}
    menuItem2={<MenuItem to="/blog">Blog</MenuItem>}
  />;
}

export default Layout;
