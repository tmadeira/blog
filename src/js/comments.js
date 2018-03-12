const reply = function(event) {
  event.preventDefault();

  const form = document.getElementById('comment-form');
  form.parentNode.removeChild(form);

  const container = event.target.parentNode;
  container.classList.add('replying');
  container.appendChild(form);
  form.querySelector('#name').focus();

  document.getElementById('replyTo').value = event.target.getAttribute('rel');
};

const cancel = function(event) {
  event.preventDefault();

  const container = event.target.parentNode;
  const form = document.getElementById('comment-form');
  container.classList.remove('replying');
  container.removeChild(form);

  const comments = document.getElementById('comments');
  comments.parentNode.insertBefore(form, comments.nextSibling);

  document.getElementById('replyTo').value = '';
}

export default function setupComments() {
  const replyButtons = document.querySelectorAll('.reply-button');
  for (let i = 0; i < replyButtons.length; i++) {
    replyButtons[i].addEventListener('click', reply);
  }

  const cancelButtons = document.querySelectorAll('.reply-cancel');
  for (let i = 0; i < cancelButtons.length; i++) {
    cancelButtons[i].addEventListener('click', cancel);
  }

  if (window.location.hash.match(/^#comment-/)) {
    const id = window.location.hash.replace(/^#/, '');
    document.getElementById(id).classList.add('show');
    window.setTimeout(() => {
      document.getElementById(id).classList.remove('show');
    }, 3000);
  }
}
