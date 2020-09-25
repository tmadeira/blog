import {Prism} from 'react-syntax-highlighter';

export default function Code({language, value}) {
  return (
    <Prism language={language}>
      {value}
    </Prism>
  );
};
