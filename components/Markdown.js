import ReactMarkdown from 'react-markdown';
import {InlineMath, BlockMath} from 'react-katex';
import RemarkMath from 'remark-math';

import Code from './Code';

export default function Markdown({content}) {
  return (
    <ReactMarkdown
      source={content}
      plugins={[RemarkMath]}
      renderers={{
        code: Code,
        math: props => <BlockMath math={props.value} />,
        inlineMath: props => <InlineMath math={props.value} />,
      }}
    />
  );
};
