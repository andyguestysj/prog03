---
title: Recursion
permalink: /docs/recursion/
---

### Recursion

Recursion is possible because of the way frames and the stack work. Here is how.

#### Recursive explonential calculation
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">int exp(int i) 
{
  if (i==1)
    return 1;
  else
    return (i * exp(i-1));
} 
</code></pre>
<ul>
<li>To calculate exponential</li>
<li>5! = 5*4*3*2*1</li>
<li>4! = 4*3*2*1</li>
<li>5! = 5 * 4!</li>
<li>1! = 1</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion1.png" alt="recursion">

    </div>
</div>


#### Program starts
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  <b>int myExp</b> = exp(5);
} 

int exp(int i) 
{
  if (i==1)
    return 1;
  else
    return (i * exp(i-1));
} 
</code></pre>
<ul>
<li>main() frame created as usual</li>
<li>myExp created as a variable in main() frame</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion2.png" alt="recursion">

    </div>
</div>


#### exp(5) called
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">main()
{
  int myExp = <b>exp(5);</b>
} 

int exp(int i) 
{
  if (i==1)
    return 1;
  else
    return (i * exp(i-1));
} 
</code></pre>
<ul>
<li>exp(5) called and a frame is created for exp()</li>
<li>i is created in exp() and the value 5 is passed in to it</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion3.png" alt="recursion">

    </div>
</div>


#### exp(4) called
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">main()
{
  int myExp = exp(5);
} 

int exp(int i) 
{
  <b>if (i==1)</b>
    return 1;
  <b>else</b>
    return (i * <b>exp(i-1)</b>);
} 
</code></pre>
<ul>
  <li>i is not equal to 1</li>
    <ul><li>So do the else, have to evaluate exp(i-1) first</li></ul>
  <li>So we call exp(4), which means we need to </li>
     <ul>
      <li>create a new frame for another exp()</li>
      <li>create an i in the new exp() frame and set it to 4</li>
      </ul>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion4.png" alt="recursion">

    </div>
</div>