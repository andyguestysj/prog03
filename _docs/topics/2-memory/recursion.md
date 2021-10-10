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
  int total;
  if (i==1)
    total = 1;
  else
  {
    total = (i * exp(i-1));    
  }
  return total;
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
  <b><I>int myExp</I></b> = exp(5);
} 

int exp(int i) 
{  
  int total;
  if (i==1)
    total = 1;
  else
  {
    total = (i * exp(i-1));    
  }
  return total;
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


#### exp(5) Called
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  int myExp = <B><I>exp(5);</I></B>
} 

<B><I>int exp(int i)</I></B>
{  
  int total;
  if (i==1)
    total = 1;
  else
  {
    total = (i * exp(i-1));    
  }
  return total;
} 
</code></pre>
<ul>
<li>exp(5) frame created</li>
<li>local variable i created for the parameter</li>
<li>parameter copied in to local variable i</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion3.png" alt="recursion">

    </div>
</div>

#### Local Variable total created in exp(5) frame
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  int myExp = exp(5);
} 

int exp(int i) 
{  
  <B><I>int total;</I></B>
  if (i==1)
    total = 1;
  else
  {
    total = (i * exp(i-1));    
  }
  return total;
} 
</code></pre>
<ul>
<li>exp(5) frame created</li>
<li>local variable i created for the parameter</li>
<li>parameter copied in to local variable i</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion4.png" alt="recursion">

    </div>
</div>

#### i > 1 so exp(4) Called
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  int myExp = exp(5);
} 

<B><I>int exp(int i)</I></B>
{  
  int total;
  if (i==1)
    total = 1;
  else
  {
    <B><I>total = (i * exp(i-1));</I></B>
  }
  return total;
} 
</code></pre>
<ul>
<li>i is not 1, total = 5 * exp(4)</li>
<li>call exp(4)</li>
<li>exp(4) frame added to stack</li>
<li>parameter value, 4, copied to local variable i in exp(4) frame</li>
<li>total created exp(4) frame</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion5.png" alt="recursion">

    </div>
</div>

#### i > 1 so exp(3) Called
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  int myExp = exp(5);
} 

<B><I>int exp(int i)</I></B>
{  
  int total;
  if (i==1)
    total = 1;
  else
  {
    <B><I>total = (i * exp(i-1));</I></B>
  }
  return total;
} 
</code></pre>
<ul>
<li>i is not 1, total = 4 * exp(3)</li>
<li>call exp(3)</li>
<li>exp(3) frame added to stack</li>
<li>parameter value, 3, copied to local variable i in exp(3) frame</li>
<li>total created exp(3) frame</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion6.png" alt="recursion">

    </div>
</div>

#### i > 1 so exp(2) Called
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  int myExp = exp(5);
} 

<B><I>int exp(int i)</I></B>
{  
  int total;
  if (i==1)
    total = 1;
  else
  {
    <B><I>total = (i * exp(i-1));</I></B>
  }
  return total;
} 
</code></pre>
<ul>
<li>i is not 1, total = 3 * exp(2)</li>
<li>call exp(4)</li>
<li>exp(2) frame added to stack</li>
<li>parameter value, 2, copied to local variable i in exp(2) frame</li>
<li>total created exp(2) frame</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion7.png" alt="recursion">

    </div>
</div>

#### i > 1 so exp(1) Called
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  int myExp = exp(5);
} 

<B><I>int exp(int i)</I></B>
{  
  int total;
  if (i==1)
    total = 1;
  else
  {
    <B><I>total = (i * exp(i-1));</I></B>
  }
  return total;
} 
</code></pre>
<ul>
<li>i is not 1, total = 2 * exp(1)</li>
<li>call exp(1)</li>
<li>exp(1) frame added to stack</li>
<li>parameter value, 1, copied to local variable i in exp(1) frame</li>
<li>total created exp(1) frame</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion8.png" alt="recursion">

    </div>
</div>

#### i == 1 We stop recursing
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  int myExp = exp(5);
} 

<B><I>int exp(int i)</I></B>
{  
  int total;
  if (i==1)
    total = 1;
  else
  {
    <B><I>total = (i * exp(i-1));</I></B>
  }
  <B><I>return total;</I></B>
} 
</code></pre>
<ul>
<li>i is 1, total = 1</li>
<li>return 1 to calling method - exp(2)</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion9.png" alt="recursion">

    </div>
</div>

#### We finalise exp(2)
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  int myExp = exp(5);
} 

<B><I>int exp(int i)</I></B>
{  
  int total;
  if (i==1)
    total = 1;
  else
  {
    <B><I>total = (i * exp(i-1));</I></B>
  }
  <B><I>return total;</I></B>
} 
</code></pre>
<ul>
<li>total = 2 * value returned here = 2 * 1 = 2</li>
<li>return 2 to calling method - exp(3)</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion10.png" alt="recursion">

    </div>
</div>

#### We finalise exp(3)
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  int myExp = exp(5);
} 

<B><I>int exp(int i)</I></B>
{  
  int total;
  if (i==1)
    total = 1;
  else
  {
    <B><I>total = (i * exp(i-1));</I></B>
  }
  <B><I>return total;</I></B>
} 
</code></pre>
<ul>
<li>total = 3 * value returned here = 3 * 2 = 6</li>
<li>return 6 to calling method - exp(4)</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion11.png" alt="recursion">

    </div>
</div>

#### We finalise exp(4)
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  int myExp = exp(5);
} 

<B><I>int exp(int i)</I></B>
{  
  int total;
  if (i==1)
    total = 1;
  else
  {
    <B><I>total = (i * exp(i-1));</I></B>
  }
  <B><I>return total;</I></B>
} 
</code></pre>
<ul>
<li>total = 4 * value returned here = 4 * 6 = 24</li>
<li>return 24 to calling method - exp(5)</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion12.png" alt="recursion">

    </div>
</div>

#### We finalise exp(5)
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  int myExp = exp(5);
} 

<B><I>int exp(int i)</I></B>
{  
  int total;
  if (i==1)
    total = 1;
  else
  {
    <B><I>total = (i * exp(i-1));</I></B>
  }
  <B><I>return total;</I></B>
} 
</code></pre>
<ul>
<li>total = 5 * value returned here = 5 * 24 = 120</li>
<li>return 120 to calling method - main()</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion13.png" alt="recursion">

    </div>
</div>


#### Program ends, stack is empty
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java"><b>main() </b>
{
  int myExp = exp(5);
} 

int exp(int i)
{  
  int total;
  if (i==1)
    total = 1;
  else
  {
    total = (i * exp(i-1));
  }
  return total;
} 
</code></pre>
<ul>
<li>program ends</li>
<li>main() frame deleted</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/recursion14.png" alt="recursion">

    </div>
</div>