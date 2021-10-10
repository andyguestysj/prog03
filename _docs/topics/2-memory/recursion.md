---
title: Recursion
permalink: /docs/recursion/
---

Recursion is a programming technique that involves a method calling itself. Recursion is possible because of the way frames and the stack work. Here is how.

#### Recursive exponential calculation
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
int exp(int i) 
{  
  if (i==1)
    return 1;
  else
  {
    int total = (i * exp(i-1));
    return total;
  }
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
  {
    int total = (i * exp(i-1));
    return total;
  }
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
  {
    int total = (i * exp(i-1));
    return total;
  }
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

#### Local total created in exp(5) Frame
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
  {
    <b>total</b> = (i * exp(i-1));
    return total;
  }
} 
</code></pre>
<ul>
  <li>i is not equal to 1</li>  
    <ul><li>So do the else, create <i>total<i> local variable</li></ul>  
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion4.png" alt="recursion">

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
  {
    total = (i * <b>exp(i-1)</b>);
    return total;
  }
} 
</code></pre>
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


#### exp(3) called
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
  <li>So we call exp(3), which means we need to </li>
     <ul>
      <li>create a new frame for another exp()</li>
      <li>create an i in the new exp() frame and set it to 3</li>
      </ul>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion5.png" alt="recursion">

    </div>
</div>


#### exp(2) called
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
  <li>So we call exp(2), which means we need to </li>
     <ul>
      <li>create a new frame for another exp()</li>
      <li>create an i in the new exp() frame and set it to 2</li>
      </ul>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion6.png" alt="recursion">

    </div>
</div>


#### exp(1) called
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
  <li>So we call exp(1), which means we need to </li>
     <ul>
      <li>create a new frame for another exp()</li>
      <li>create an i in the new exp() frame and set it to 1</li>
      </ul>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion7.png" alt="recursion">

    </div>
</div>


#### exp(1) completes and returns 1
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">main()
{
  int myExp = exp(5);
} 

int exp(int i) 
{
  <b>if (i==1)</b>
    <b>return 1;</b>
  else
    return (i * exp(i-1));
} 
</code></pre>
<ul>
  <li>i is equal to 1</li>
    <ul><li>So we return 1</li>
      <li>and delete the current exp() frame</li>
      </ul>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion6.png" alt="recursion">

    </div>
</div>


#### exp(2) completes and returns 2
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">main()
{
  int myExp = exp(5);
} 

int exp(int i) 
{
  if (i==1)
    return 1;
  else
    <b>return (i * exp(i-1));</b>
} 
</code></pre>
<ul>
  <li>We return to the previous exp() frame at the point we left</li>
<li>Here i is 2 and exp(1) is the value we just returned i.e. 1</li>
<li>So we return 2*1 from here and delete this frame</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion5.png" alt="recursion">

    </div>
</div>


#### exp(3) completes and returns 6
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">main()
{
  int myExp = exp(5);
} 

int exp(int i) 
{
  if (i==1)
    return 1;
  else
    <b>return (i * exp(i-1));</b>
} 
</code></pre>
<ul>
  <li>We return to the previous exp() frame at the point we left</li>
<li>Here i is 3 and exp(2) is the value we just returned i.e. 2</li>
<li>So we return 3*2 or 6 from here and delete this frame</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion4.png" alt="recursion">
    </div>
</div>

#### exp(4) completes and returns 24
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">main()
{
  int myExp = exp(5);
} 

int exp(int i) 
{
  if (i==1)
    return 1;
  else
    <b>return (i * exp(i-1));</b>
} 
</code></pre>
<ul>
  <li>We return to the previous exp() frame at the point we left</li>
<li>Here i is 4 and exp(3) is the value we just returned i.e. 6</li>
<li>So we return 4*6 or 24 from here and delete this frame</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion3.png" alt="recursion">
    </div>
</div>

#### exp(5) completes and returns 120
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">main()
{
  int myExp = exp(5);
} 

int exp(int i) 
{
  if (i==1)
    return 1;
  else
    <b>return (i * exp(i-1));</b>
} 
</code></pre>
<ul>
  <li>We return to the previous exp() frame at the point we left</li>
<li>Here i is 5 and exp(4) is the value we just returned i.e. 24</li>
<li>So we return 5*24 or 120 from here and delete this frame</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion2.png" alt="recursion">
    </div>
</div>