import * as React from "react";

export const ScreenContext = React.createContext(undefined);

const screenVariants = ["medium"];

const screenQueries = ["(min-width:600px)"];

function matchScreenVariant() {
  const index = screenQueries.findIndex((q) => window.matchMedia(q).matches);
  return index >= 0 ? screenVariants[index] : undefined;
}

export function ScreenVariantProvider(props) {
  const [value, setValue] = React.useState(matchScreenVariant());
  React.useEffect(() => {
    const handler = () => {
      const newValue = matchScreenVariant();
      if (newValue !== value) {
        setValue(newValue);
      }
    };
    window.addEventListener("resize", handler);
    return () => window.removeEventListener("resize", handler);
  }, [value]);
  return (
    <ScreenContext.Provider value={value}>
      {props.children}
    </ScreenContext.Provider>
  );
}

export default ScreenContext;
