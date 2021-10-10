---
title: Methods & Frames
permalink: /docs/intro-silly/
---

#### The Stack Grows Downwards In Memory
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  int i=1; 
  int a=4;
} 
</code></pre>
<ul>
<li>Frames are added to the stack at the highest available address (on the stack)</li>
<li>Here we illustrate this by showing the stack with the highest address at the top</li>
<li>The stack fills "downwards"</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-methods-1.png" alt="methods & frames">

    </div>
</div>



#### Each method call adds a new frame to the stack
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  int i=1; 
  int a=4;

  silly();
} 

void silly()
{
  float p=5.6f;
}
</code></pre>
<ul>
<li>When a method is <b>called</b> a new frame is added to the stack</li>
<li>A method can only access its own frame</li>
<li>Code in silly() cannot use the variables created in main()</li>
<li>A <b>frame</b> limits the <b>scope</b> of a variable</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-methods-2.png" alt="methods & frames">

    </div>
</div>


#### Frames & Variables
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  int i=1; 
  int a=4;

  silly();
} 

void silly()
{
  float p=5.6f;
  int i=3;
}
</code></pre>
<ul>
<li>This is why we can use the same variable name in different methods without changing the value everywhere
</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-methods-3.png" alt="methods & frames">

    </div>
</div>



#### Frames & Scope
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  int i=1; 
  int a=4;

  silly();
} 

void silly()
{
  float p=5.6f;
  int i=3;
  i++;
}
</code></pre>
<ul>
<li>This is why we can use the same variable name in different methods without changing the value everywhere
</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-methods-4.png" alt="methods & frames">

    </div>
</div>

<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  int i=1; 

  i = silly(i);
} 

void silly(int locali)
{
}
</code></pre>
<ul>
<li>This is why we need to pass values as parameters if we want to use them in the method
</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-methods-5.png" alt="methods & frames">

    </div>
</div>


<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  int i=1; 

  i = silly(i);
} 

void silly(int locali)
{
  locali = 3;
  return locali;
}
</code></pre>
<ul>
<li>Similarly if we want to pass back a value to the calling method we have to use a return 
</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-methods-7.png" alt="methods & frames">

    </div>
</div>


