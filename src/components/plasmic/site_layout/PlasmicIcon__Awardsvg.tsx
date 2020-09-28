/* eslint-disable */
/* tslint:disable */
/* prettier-ignore-start */
import React from "react";
import { classNames } from "@plasmicapp/react-web";

export type AwardsvgIconProps = React.ComponentProps<"svg"> & {
  title?: string;
};

export function AwardsvgIcon(props: AwardsvgIconProps) {
  const { className, style, title, ...restProps } = props;
  return (
    <svg
      xmlns={"http://www.w3.org/2000/svg"}
      viewBox={"0 0 768 768"}
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
          "M479.552 493.568l24 180.864-103.072-61.856c-9.952-5.888-22.496-6.272-32.928 0L264.48 674.432 288.512 493.6C317.984 505.472 350.24 512 384 512s66.016-6.56 95.552-18.432zm11.072-77.856a31.554 31.554 0 00-5.216 3.36C455.968 437.408 421.248 448 384 448c-53.024 0-100.992-21.44-135.776-56.224S192 309.024 192 256s21.44-100.992 56.224-135.776S330.976 64 384 64s100.992 21.44 135.776 56.224S576 202.976 576 256s-21.44 100.992-56.224 135.776a192.123 192.123 0 01-29.152 23.936zM228.48 459.36l-36.192 272.416c-2.336 17.504 9.984 33.6 27.52 35.936 7.488.992 14.752-.704 20.672-4.288L384 677.312l143.552 86.112c15.168 9.088 34.816 4.192 43.904-10.976a31.781 31.781 0 004.288-20.672l-36.16-272.48a259.472 259.472 0 0025.44-22.304C611.296 390.72 640 326.688 640 256s-28.704-134.72-74.976-181.024S454.688 0 384 0 249.28 28.704 202.976 74.976 128 185.312 128 256s28.704 134.72 74.976 181.024c8 8 16.512 15.456 25.472 22.336z"
        }
      ></path>
    </svg>
  );
}

export default AwardsvgIcon;
/* prettier-ignore-end */
