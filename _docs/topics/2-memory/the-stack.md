---
title: The Stack
permalink: /docs/the-stack/
---

### The Stack

The stack is used to store data as code is executed. Every time a method is called a new area is added to the stack. This area is called a **frame**. Note that this is a **frame** for each time a method is called, not one frame for each method.  

The frame for a method call stores the parameters passed in a method call and all the local variables used within that module. When the method finishes running the associated frame is deleted from the stack.

#### A Simple Java Application
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args)  
{  
  int i=1;  
}
</code></pre>
<ul>
<li>A frame is created on the stack</li>
<li>The stack is filled from zero upwards</li>
<li>Within the main() frame all local variables are stored</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/simple-java-stack-1.png" alt="simple java stack">

    </div>
</div>

#### Data is binary
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args)  
{  
  int i=1;  
}
</code></pre>
<ul>
<li>All data is stored in binary</li>
<li>(shown here as one byte)</li>
<li>(actual amount varies by chip)</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/simple-java-stack-2-binary.png" alt="simple java stack">

    </div>
</div>

#### Data stored smallest part first
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args)  
{  
  int i=1;  
}
</code></pre>
<ul>
<li>All data is stored in binary</li>
<li>Is is stored as least significant "part" first</li>
<li>(again, part size varies by chip)</li>
<li>We'll typically just show the numbers in decimal</li>
<li>We typically only need to deal with binary in Assembly</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/simple-java-stack-2-binary2.png" alt="simple java stack">

    </div>
</div>

