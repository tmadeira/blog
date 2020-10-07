---
title: "Retrospective: new plugin for WordPress"
date: 2012-02-01T00:20:03+00:00
url: /2012/01/retrospective/
tags:
  - códigos
  - css
  - html
  - javascript
  - php
  - plugin
  - programação
  - retrospective
  - scripts
  - software livre
  - wordpress
---

I’ve just wrote my first WordPress public plugin, that I’m licensing under GPL v3. This post is to make it public. I’m writing in English because the [WordPress plugin directory][1] asks me to provide a plugin page to host the files there and I’ll provide the URL of this post. **Update:** The plugin is now in the WordPress plugin directory: [wordpress.org/extend/plugins/retrospective/][2]

---

The website of the brazilian newspaper O Estado de São Paulo has a nice way to display news in a retrospective-style (check [this screenshot][3] or [this link][4] — Flash required).

Wouldn’t it be nice if we could display WordPress posts in our pages and categories in the same way just by using a shortcode? The possibilities are many. That’s why I wrote the **Retrospective** plugin for WordPress.

It has at least two advantages over the version you just saw:

1. Does not require Flash (its implementation uses only CSS and JavaScript/jQuery)
2. Has a option to respect the (time-)scale of the posts.

Its use is very simple. Wherever you add the shortcode [`retrospective`] the plugin will draw that cool retrospective. The shortcode supports several attributes:

- `count` — limit the number of posts to be displayed (default = 10; use -1 to display all)
- `cat` — display posts with category IDs comma-separated (default = display all posts)
- `width` — the width of the timeline in pixels (default = 600)
- `delay` — the time of the focus change animation in milisseconds (default = 1000)
- `scale` — if set, respect the time scale in the distances between the points in the timeline (default = false)
- `image_width, image_height` — the dimensions of the thumbnail images in pixels (default = 300×180)
- `image_border_size` — the size of the image’s border in pixels (default = 7)
- `image_border_color` — the color of the image’s border in hexa RGB (default = 000000)
- `image_margin` — the space between the images (default = 5)
- `date_format` — the date format in [PHP format][5] (default = d/m/Y)

---

### Some screenshots

Here is a screenshot from [juntos.org.br][6] with `scale=true` (in the link you can see it working):

![Screenshot (Retrospective plugin in juntos.org.br)](/wp-content/uploads/2012/01/ss1.jpg)

And here is a screenshot from a fresh WordPress install (TwentyEleven theme without modifications):

![Screenshot (Retrospective plugin in TwentyEleven theme](/wp-content/uploads/2012/01/ss2.jpg)

### Customizing

#### Post thumbnails

For better results, I suggest always adding post thumbnails to your posts and using [registered image sizes][7] in `image_width` and `image_height` attributes.

#### Styling retrospectives

The generated HTML is very easy to style (but just be careful with margins and paddings, they’re set with `!important` attribute — I did it to try not to break with any theme). Here is a sample:

```html
<div id="retro-uniquehash" class="retrospective">
  <!-- TIMELINE -->
  <ul class="time">
    <li rel="0">
      <a href="permalink" style="left:0px;"><span>date</span></a>
    </li>
    <li rel="1">
      <a href="permalink" style="left:300px;"><span>date</span></a>
    </li>
    <li rel="2">
      <a href="permalink" style="left:600px;"><span>date</span></a>
    </li>
  </ul>

  <!-- PHOTOS -->
  <div class="photos">
    <ul>
      <li rel="0">
        <a href="permalink" title="title"
          ><img src="file" class="wp-post-image"
        /></a>
      </li>
      <li rel="1">
        <a href="permalink" title="title"
          ><img src="file" class="wp-post-image"
        /></a>
      </li>
      <li rel="2">
        <a href="permalink" title="title"
          ><img src="file" class="wp-post-image"
        /></a>
      </li>
    </ul>
  </div>

  <!-- POSTS -->
  <ul class="posts">
    <li rel="0">
      <a href="permalink" title="title">
        <h2>Title <span>(date)</span></h2>
        <p>Excerpt</p>
      </a>
    </li>
    <li rel="1">
      <a href="permalink" title="title">
        <h2>Title <span>(date)</span></h2>
        <p>Excerpt</p>
      </a>
    </li>
    <li rel="2">
      <a href="permalink" title="title">
        <h2>Title <span>(date)</span></h2>
        <p>Excerpt</p>
      </a>
    </li>
  </ul>
</div>
```

#### Styling a specific retrospective

The generated hash takes in consideration all the attributes sent to the shortcode and also how many retrospectives appeared before in the parsing of the actual page. I made it that way to allow users to set up two exactly equal retrospectives in the same page. Because of that, I don’t recommend setting styles for `#retro-uniquehash`. I think a reasonable solution for this issue is to make add an outer container.

### Download

**Here is the code for download:** [retrospective.zip][8]

<small><strong>\* Warning:</strong> Please consider I’m using a <a href="http://catb.org/~esr/writings/homesteading/">bazaar approach</a> here. Be aware that the plugin probably has a lot of bugs (and please tell me if you catch any).</small>

I hope you enjoy it. Have fun and please let me have your feedback! :)

[1]: https://wordpress.org/extend/plugins/add/
[2]: https://wordpress.org/extend/plugins/retrospective/
[3]: /wp-content/uploads/2012/01/estadao.jpg
[4]: http://www.estadao.com.br/especiais/choque-nas-ruas,158638.htm
[5]: http://php.net/date
[6]: http://juntos.org.br/juntos/internet/
[7]: https://codex.wordpress.org/Function_Reference/add_image_size
[8]: /wp-content/uploads/2012/01/retrospective.zip
