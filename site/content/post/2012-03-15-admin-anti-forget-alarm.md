---
title: 'WordPress plugin: Admin Anti-forget Alarm'
type: post
date: 2012-03-15T06:11:03+00:00
url: /2012/03/admin-anti-forget-alarm/
featured_image: /wp-content/uploads/2012/03/wordpress-plugin.jpg
categories:
  - WordPress
tags:
  - códigos
  - php
  - plugin
  - programação
  - scripts
  - Software Livre
  - wordpress

---
I wrote a small WordPress plugin to prevent users from publishing a post without excerpt or thumbnail, or with a too big excerpt, or with a too small thumbnail, or with an uppercase-only title.

{{< figure src="/wp-content/uploads/2012/03/wordpress1.png" title="Screenshot do plugin" >}}

_This screenshot is showing some of the messages the plugin displays in portuguese._

For some of my websites it’s important to require the editors to fix some stuff before publishing something, and it looks like this is a useful feature for [other people][1] as well. There is even a [Require Thumbnail][2] plugin in the WordPress Plugin Directory that seems to do one of the things I’ve just implemented.

The plugin works with two different types of requirements: ths first generates errors (i.e., you can’t publish if you don’t fix it) and the second generates warnings (i.e., you will receive a message but you can proceed to publish if you really want to do that).

I thought of not releasing the plugin (because it’s written in Portuguese and you don’t have a cool interface to decide what’s required yet), but in a fashion of overstated bazaar I decided to push the code anyway (without putting in the WordPress plugin directory, of course) so that other people can collaborate if they want to. Take a look :)

**Github project home page:** <https://github.com/tmadeira/antiforget>

**Git repository to clone:** https://github.com/tmadeira/antiforget.git

**Code (PHP):** <https://github.com/tmadeira/antiforget/blob/master/antiforget.php>

**Download:** [antiforget.zip][3] _(this is pre-alpha: I provide no warranty!)_

 [1]: http://meyerweb.com/eric/thoughts/2008/06/10/wanted-excerpt-exacter/
 [2]: https://wordpress.org/extend/plugins/require-thumbnail/
 [3]: https://github.com/tmadeira/antiforget/zipball/master
