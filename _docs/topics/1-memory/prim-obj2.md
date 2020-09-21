---
title: Primitives Vs Objects II
permalink: /docs/prim-obj2/
---



### Why objects and primitives different
Primitive variables are small and of known size  
* They can be passed very quickly by variable  
* Removed automatically with the frame  
Objects vary in size  
* They are big and would be slow to pass around as parameters  
* Their addresses can be passed quickly like primitive variables.  
* Hang around in memory until garbage collection gets round to them  


### Primitives vs Objects
<div class="row">
    <div class="col-md-6">
<b>Stack</b>
<ul>
<li>Allocated as methods are called</li>
<li>Deallocated when method exits</li>
<li>Faster</li>
<li>Limited in size</li>
<li>Threadsafe – threads have their own stacks</li>
</ul>
    </div>
    <div class="col-md-6">
    <b>Heap</b>
<ul>
<li>Allocated when objects are created</li>
<li>Deallocated when garbage collector realises there is no link to object</li>
<li>Slower</li>
<li>Not limited in size</li>
<li>Not threadsafe – the heap is shared</li>
</ul>
    </div>
</div>


### Instance vs Local Variables
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public class simple
{
  private int num;

  public bigger(int a) 
  { 
    int b = 3;
    num = a + b; 
  }
}
</code></pre>
    </div>
    <div class="col-md-6">
<ul>
<li><b>num</b> is an <i>instance variable</i></li>
<ul>
<li>It is created when the object is created </li>
<li>It is stored in the heap</li>
</ul>
<li><b>b</b> is a <i>local variable</i></li>
<ul>
<li>It is created when the method is called</li>
<li>It is stored in the method frame</li>
</ul>
<li><b>a</b> is also a <i>local variable</i></li>
<li>Remember the code itself is stored elsewhere in memory</li>
</ul>

    </div>
</div>


### Objects as "="
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  simple s_1 = new simple(5);
  simple s_2 = new simple(7);
}
</code></pre>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-14.png" alt="java heap example">

    </div>
</div>


### Objects as "="
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  simple s_1 = new simple(5);
  simple s_2 = new simple(7);

  s_2 = s_1;
}
</code></pre>
<ul>
<li>Assigning one object to another <i>copies the link <b>not</b> the object</i></li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-15.png" alt="java heap example">

    </div>
</div>

### Cloning an object
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  simple s_1 = new simple(5);

  simple s_2 = (simple) s_1.clone();
  
}
</code></pre>
<ul>
<li>Most Java classes come with a method called <b>clone()</b></li>
<li>This method returns a new object with the same values as the object is is called on</li>
<li>You would need to create your own clone method for your own classes</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-16.png" alt="java heap example">

    </div>
</div>

### Objects - Testing Equality
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  simple s_1 = new simple(5);
  simple s_2 = new simple(5);

  if (s_1 == s_2)
  …
}
</code></pre>
<ul>
<li>This will fail, it will compare the two memory addresses and they will be different</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-17.png" alt="java heap example">

    </div>
</div>


### Objects - Testing Equality
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">
public main()
{
  simple s_1 = new simple(5);
  simple s_2 = new simple(5);

  if (s_1.equals(s_2))
  …
}
</code></pre>
<ul>
<li>This will succeed</li>
<li>Most Java classes implement equals()</li>
<li>You will need to implement equals for your own classes</li>
<li markdown="1">[Instructions on doing this](https://www.sitepoint.com/implement-javas-equals-method-correctly/)</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/heap1-17.png" alt="java heap example">

    </div>
</div>
