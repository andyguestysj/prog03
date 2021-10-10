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

#### exp(4) Called
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