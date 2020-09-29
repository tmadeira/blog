/* eslint-disable */
/* tslint:disable */
/* prettier-ignore-start */
import React from "react";
import { classNames } from "@plasmicapp/react-web";

export function GitlabsvgIcon(props) {
  const { className, style, title, ...restProps } = props;
  return (
    <svg
      xmlns={"http://www.w3.org/2000/svg"}
      viewBox={"0 0 28 28"}
      height={"1em"}
      width={"1em"}
      style={{
        fill: "currentcolor",
        ...(style || {}),
      }}
      className={classNames("plasmic-default__svg", className)}
      {...restProps}
    >
      {title && <title>{title}</title>}

      <path
        d={
          "M1.625 11.031L14 26.89.437 17.046a1.092 1.092 0 01-.391-1.203l1.578-4.813zm7.219 0h10.313L14.001 26.89zM5.75 1.469l3.094 9.562H1.625l3.094-9.562a.548.548 0 011.031 0zm20.625 9.562l1.578 4.813a1.09 1.09 0 01-.391 1.203l-13.563 9.844 12.375-15.859zm0 0h-7.219l3.094-9.562a.548.548 0 011.031 0z"
        }
      ></path>
    </svg>
  );
}

export default GitlabsvgIcon;
/* prettier-ignore-end */
