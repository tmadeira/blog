/* eslint-disable */
/* tslint:disable */
/* prettier-ignore-start */
/** @jsx createPlasmicElementProxy */
// This class is auto-generated by Plasmic; please do not edit!
// Plasmic Project: oH8FCw6CW4Lg76cBx26GoT
// Component: -L2AeWmd9I
import * as React from "react";
import {
  classNames,
  Renderer,
  createPlasmicElementProxy,
  PlasmicSlot,
  deriveRenderOpts
} from "@plasmicapp/react-web";
import { ScreenContext } from "../PlasmicGlobalVariant__Screen"; // plasmic-import: fOWX3a-rE7c/globalVariant
import "@plasmicapp/react-web/lib/plasmic.css";
import "../plasmic__default_style.css"; // plasmic-import: global/defaultcss
import "./plasmic_site_layout.css"; // plasmic-import: oH8FCw6CW4Lg76cBx26GoT/projectcss
import "./PlasmicSection.css"; // plasmic-import: -L2AeWmd9I/css

export const PlasmicSection__VariantProps = new Array();

export const PlasmicSection__ArgProps = new Array("children", "title");

function PlasmicSection__RenderFunc(props) {
  const { variants, args, overrides, forNode } = props;
  const globalVariants = {
    screen: React.useContext(ScreenContext)
  };

  return (
    <section
      data-plasmic-name={"root"}
      data-plasmic-override={overrides.root}
      data-plasmic-root={true}
      data-plasmic-for-node={forNode}
      data-plasmic-wrap-flex-child={true}
      className={classNames({
        "Section__root--baseMedium__1sLjB_2ZOq_MVUpr": true,
        Section__root__1sLjB: true,
        "plasmic-default__all": true,
        "plasmic-default__section": true
      })}
    >
      <div
        className={classNames({
          "Section__box--baseMedium__ESAna_2ZOq_MVUpr": true,
          Section__box__ESAna: true,
          "plasmic-default__all": true,
          "plasmic-default__div": true
        })}
      >
        <h2
          data-plasmic-name={"h2"}
          data-plasmic-override={overrides.h2}
          className={classNames({
            "Section__h2--baseMedium__68yQt_2ZOq_MVUpr": true,
            Section__h2__68yQt: true,
            "plasmic-default__all": true,
            "plasmic-default__h2": true
          })}
        >
          <PlasmicSlot
            defaultContents={"Title"}
            value={args.title}
            className={classNames({
              "Section__slotTitle--baseMedium__dfLnz_2ZOq_MVUpr": true,
              Section__slotTitle__dfLnz: true
            })}
          />
        </h2>
      </div>

      <div
        data-plasmic-wrap-flex-child={true}
        className={classNames({
          "Section__box--baseMedium__6IQfr_2ZOq_MVUpr": true,
          Section__box__6IQfr: true,
          "plasmic-default__all": true,
          "plasmic-default__div": true
        })}
      >
        <PlasmicSlot defaultContents={undefined} value={args.children} />
      </div>
    </section>
  );
}

class PlasmicSection__Renderer extends Renderer {
  constructor(variants, args) {
    super(variants, args, PlasmicSection__RenderFunc, "root");
  }
  create(variants, args) {
    return new PlasmicSection__Renderer(variants, args);
  }
  getInternalVariantProps() {
    return PlasmicSection__VariantProps;
  }
  getInternalArgProps() {
    return PlasmicSection__ArgProps;
  }
  forNode(name) {
    return super.forNode(name);
  }
}

export const PlasmicSection = function PlasmicSectionRoot(props) {
  const { variants, args, overrides } = deriveRenderOpts(props, {
    name: "root",
    descendantNames: ["root", "h2"],
    internalArgPropNames: PlasmicSection__ArgProps,
    internalVariantPropNames: PlasmicSection__VariantProps
  });

  return PlasmicSection__RenderFunc({
    variants,
    args,
    overrides,
    forNode: "root"
  });
};

PlasmicSection.h2 = function PlasmicSectionH2(props) {
  const { variants, args, overrides } = deriveRenderOpts(props, {
    name: "h2",
    descendantNames: ["h2"],
    internalArgPropNames: PlasmicSection__ArgProps,
    internalVariantPropNames: PlasmicSection__VariantProps
  });

  return PlasmicSection__RenderFunc({
    variants,
    args,
    overrides,
    forNode: "h2"
  });
};

PlasmicSection.createRenderer = () => new PlasmicSection__Renderer({}, {});

export default PlasmicSection;
/* prettier-ignore-end */