import * as React from "react";
import { PlasmicMenuItem } from "./plasmic/site_layout/PlasmicMenuItem";
import {Link} from 'gatsby';

function MenuItem({to, ...props}) {
  return (
    <Link to={to} style={{display: 'flex'}}>
      <PlasmicMenuItem {...props} />
    </Link>
  );
}

export default MenuItem;
