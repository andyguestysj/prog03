---
title: Terminal;GitLab
permalink: /docs/gitlab-terminal/
---



### Terminal Guide

These instructions are available on the Details page of your repository, with the correct URLS filled in.  

#### Adding code you cloned from somewhere to your repository

To upload a project from your machine to your new repository using the terminal, follow the instructions below.

1. Make sure you are in the folder with your code in.
2. Enter the command `git remote rename origin old-origin`  
3. Enter the command `git remote add origin URL` 
4. Enter the command `git push -u origin --all`
5. Enter the command `git push -u origin --tags`
  
The code you cloned from the original source will now be uploaded to your repository.  
**Note andy changes you have made will not be uploaded.** To upload your changes follow the **Upload Changes** section below.  

#### Adding a project you've created to your repository

If you have created a new project (rather than having cloned it from somewhere), follow the instructions below.

1. Make sure you are in the folder with your code in.
2. Enter the command `git init`
3. Enter the command `git remote add origin URL`
4. Enter the command `git add .`
5. Enter the command `git commit -m "Initial commit"`
6. Enter the command `git push origin master`

#### Uploading changes

After you have made changes to your code you need to commit and push those changes. 

1. Make sure you are in the folder with your code in.
2. Enter the command `git add .`
3. Enter the command `git commit -m "Enter commit message about changes here"`
4. Enter the command `git push origin master`

#### Pulling Changes

If you have a repository on gitlab and a local repository on your machine and the local version isn't up to date (you've made changes on another machine) follow the instruction below.  

1. Make sure you are in the folder with your code in.
2. Enter the command `git pull --all`