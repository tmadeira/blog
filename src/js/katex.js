import katex from 'katex';
window.katex = katex;

import renderMathInElement from './katex-contrib/auto-render';

export default function setupKatex() {
  renderMathInElement(document.body);

  const spans = document.querySelectorAll('.tex-render');
  for (let i = 0; i < spans.length; i++) {
    katex.render(spans[i].innerHTML, spans[i]);
  }
}
