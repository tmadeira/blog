import * as React from "react";
import { PlasmicMenuItem } from "./plasmic/site_layout/PlasmicMenuItem";
import {Link} from 'gatsby';

function MenuItem({to, ...props}) {
  return (
    <li style={{display: 'flex'}}>
      <Link to={to} style={{display: 'flex'}}>
        <PlasmicMenuItem {...props} />
      </Link>
    </li>
  );
}

export default MenuItem;
