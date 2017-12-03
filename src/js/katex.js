import katex from 'katex';
window.katex = katex;

import renderMathInElement from './katex-contrib/auto-render';

export default function setupKatex() {
  renderMathInElement(document.body);
}
