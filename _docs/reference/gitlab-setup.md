---
title: Gitlab Setup
permalink: /docs/gitlab-setup/
---

You need to setup your Linux account so you can access Gitlab - you should only need to do this once on your account. You **should not** need to do this on Windows or Mac machines.  

#### Accessing GitLab

Howto - [http://www.ysjcs.net/linux_ssh_git.php](http://www.ysjcs.net/linux_ssh_git.php)

In terminal:

```console
sudo apt-get -y install xclip
ssh-keygen -t rsa -N "" -f ~/.ssh/id_rsa
cat ~/.ssh/id_rsa.pub | xclip -sel clip
```

Log into [gitlab](https://git.ysjcs.net:8888/users/sign_in) then click on the icon at the top right of the page, choose Settings and then SSH keys from the menu on the left.

Click in the Key box and press Ctrl+V (paste) then click Add key.

You should now be able to use git without entering a password. If a git command asks you for a password something has gone wrong with this key setup, so get in touch.
