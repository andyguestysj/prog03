---
title: Stack Step By Step
permalink: /docs/stack-timelapse/
---

### The Stack Step By Step

#### Start
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  int i=1; 

  i = silly(i);
} 

int silly(int locali)
{
  locali = 3;
  return locali;
}
</code></pre>
<ul>
<li>The stack isn’t really empty, other applications are running but as far as this application is concerned there is only an empty stack
</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-time-1.png" alt="simple java stack">

    </div>
</div>

#### Program starts
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>public static void main(String[] args) </b>
{
  int i=1; 

  i = silly(i);
} 

int silly(int locali)
{
  locali = 3;
  return locali;
}
</code></pre>
<ul>
<li>main() frame added to stack
</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-time-2.png" alt="simple java stack">

    </div>
</div>


#### Variable created
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  <b>int i=1; </b>

  i = silly(i);
} 

int silly(int locali)
{
  locali = 3;
  return locali;
}
</code></pre>
<ul>
<li>i variable created in the main() frame
</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-time-3.png" alt="simple java stack">

    </div>
</div>


#### Method call
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  int i=1; 

  <b>i = silly(i);</b>
} 

<b>int silly(int locali)</b>
{
  locali = 3;
  return locali;
}
</code></pre>
<ul>
<li>(Two steps) silly() frame added to stack, locali variable created with a value passed in from main()
</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-time-4.png" alt="simple java stack">

    </div>
</div>


#### Variable set
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  int i=1; 

  i = silly(i);
} 

int silly(int locali)
{
  <b>locali = 3;</b>
  return locali;
}
</code></pre>
<ul>
<li>locali value in silly() changed to 3
</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-time-5.png" alt="simple java stack">

    </div>
</div>


#### Value returned
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  int i=1; 

  i = silly(i);
} 

int silly(int locali)
{
  locali = 3;
  <b>return locali;</b>
}
</code></pre>
<ul>
<li>locali value in silly() returned to main() and stored in i
</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-time-6.png" alt="simple java stack">

    </div>
</div>


#### Main finishes and program closes
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  int i=1; 

  i = silly(i);
<b>}</b> 

int silly(int locali)
{
  locali = 3;
  return locali;
}
</code></pre>
<ul>
<li>main() frame deleted as method exits
</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-time-8.png" alt="simple java stack">

    </div>
</div>