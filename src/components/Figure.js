export default function Figure({ alt, src }) {
  return (
    <figure>
      <img src={src} alt={alt} />
      {alt ? <figcaption>{alt}</figcaption> : null}
    </figure>
  );
}
