import {Prism} from 'react-syntax-highlighter';
import {vscDarkPlus} from 'react-syntax-highlighter/dist/cjs/styles/prism';

export default function Code({language, value}) {
  return (
    <Prism language={language} style={vscDarkPlus}>
      {value}
    </Prism>
  );
};
