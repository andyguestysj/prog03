---
title: Methods & Frames
permalink: /docs/intro-silly/
---

#### Data stored smallest part first
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args) 
{
  int i=1; 
  int a=4;
} 

</code></pre>
<ul>
<li>Frames are added to the stack at the lowest available address (on the stack)</li>
<li>We illustrate this by showing the stack with the lowest address at the bottom</li>
<li>The stack fills "upwards"</li>
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
<li>When a method is <b>called</b> a new fram is added to the stack</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/stack-methods-2.png" alt="methods & frames">

    </div>
</div>







## <a name="javamem"></a>Java Memory Usage


