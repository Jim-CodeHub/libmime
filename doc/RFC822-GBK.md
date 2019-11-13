
ARPA 互联网文本消息标准
	
**<p align="center"><font size=4>前言</font></p></H1>**
<p style="line-height:25px">
&ensp;&ensp;&ensp;&ensp;1997年，<strong>Arpanet</strong>采用了几种信息标准用以在其主机中发送文本信息（邮件），人们意识到有必要将其编成法典，并提供那些即将出现的功能，因此由Crocker、Vittal、Pogran和Henderson编写了RFC#733：“ARPA网络文本消息格式标准”诞生了。该标准试图避免了对现有软件的重大更改，同时提供了几种新的特性。  <br>
 &ensp;&ensp;&ensp;&ensp;本文档修订了RFC#733中的规范，以满足大而复杂的ARPA网需求。一些RFC#733中的特性没有得到足够的任何，为简化标准和软件，这些特性都被删除了。使用了不同的寻址方案来处理网络间的邮件并引入了重传的概念。  <本文档旨在应用于ARPA网络，但已作出努力来摆脱这个依赖以适应更多的通信网络。  <br>
&ensp;&ensp;&ensp;&ensp;RFC#733规范的制定花了一年的时间，它使用了ARPANET邮件环境，为讨论所被包含的性能提供了一个持续运行的论坛。来自全国各地的二十多人参与了最初的讨论。这次修订规范的开发已经类似地使用了基于网络邮件的小组讨论。两个规范的工作都从参与者的评论和想法中受益匪浅。  <br>
&ensp;&ensp;&ensp;&ensp;在RFC#733中的语法最初是在Backus-Naur格式（BNF）元素语言中指定的。SRI国际的Ken L.Harrenstien负责对BNF重新编码来对其增强以使其表示更小并更容易被理解。  </p>

<font size=3>1. 介绍</font>  

1.1. 适用范围  
<p style="line-height:25px">
&ensp;&ensp;&ensp;&ensp;该标准规范了在“电子邮件”框架内电脑用户之间发送的文本信息的语法。<strong>该标准取代了RFC#733</strong>。  <br>
&ensp;&ensp;&ensp;&ensp;在上下文中，消息被视为一个信封和内容，信封包含需要完成传输和传递的任何信息，内容组成了向接收者传递的对象。该标准仅适用于格式和一些消息内容语义，不包含信封中的信息规范。  <br></p>
<p style="line-height:25px; display:none">&ensp;&ensp;&ensp;&ensp;一些消息系统可能利用来自内容的信息来创建信封。本标准旨在帮助程序获取此类信息。一些消息系统可能以不同于该标准的格式存储信息，本标准旨在严格定义主机之间应该传递的消息内容格式。  <br>
&ensp;&ensp;&ensp;&ensp;该标准无意规范站点使用的内部格式、所期望支持的消息系统功能和创建或读取用户接口程序的任何特性。应该区分规范需求什么和允许什么，消息可以使用消息的结构化格式组件制定的复杂而丰富，或者使用最少的此类信息保持小而简单。此外，该标准简化了消息中不同可视规格的解释；只影响信息的视觉方面而不影响对信息的解释。  <br>
&ensp;&ensp;&ensp;&ensp;正式的定义被划分为四个层次，最底层描述了本文档使用的元记号，第二层描述了基本词法分析器，它将标记提供给更高层次的分析器。接下来是总体消息规范，它允许区分单个字段。最后是几个结构字段内容的定义。</p>  

1.2. 通信框架  
<p style="line-height:25px; display:none;">
&ensp;&ensp;&ensp;&ensp;消息由文本行组成，对编码绘图、传真、语音或结构化文本没有特别的规定。没有对数据压缩或传输和存储效率的问题进行重要的考虑，并且该标准往往与所包含的比特数无关。例如字段名被定义成自由文本而不是特定的简介代码。  <br>
&ensp;&ensp;&ensp;&ensp;使用了一个通用的“备忘录”框架。也就是说，消息以严格的格式包含某些信息，然后是消息的主要部分，该格式在本文档中没有指定。严格定义的头部部分的几个字段的语法定义在本规范中，这些字段中的一些必须被包含在所有信息中。  <br>
&ensp;&ensp;&ensp;&ensp;区分头字段的语法与特定字段的内部语法是分开指定的，这种分离的目的是允许简单的解析器对消息的一般结构进行操作，而不必考虑单个头字段的详细结构。提供了附录B来帮助构建这些解析器。  <br>
&ensp;&ensp;&ensp;&ensp;除了在本文档中规定的字段外，其它字段也将得到普遍使用。必要时，这些“扩展字段”的规范将通过与发布本文档相同的机制发布。用户还可能希望扩展他们私下使用的字段集，允许这样的“用户定义字段”。  <br>
&ensp;&ensp;&ensp;&ensp;该框架严格限制了文档的语调和外观，主要用于大多数组织内通信和结构良好的组织间通信。它还可以用于某些类型的进程间通信，例如简单的文件传输和远程作业输入。一个更健壮的框架可能允许多字体、多颜色、多维度的信息编码。在大多数单机消息系统中，一个不那么健壮的消息将更严重地限制添加字段的能力和包含特定字段的决定。与纸面通信相比，有趣的是，消息的接收者可以对消息的外观进行非常大的控制，消息接收者可获得的实际控制量取决于其个人信息系统。
</p>
<font size=3>2. 符号约定</font>  
<p style="line-height:25px">
&ensp;&ensp;&ensp;&ensp;该规范使用了增强的BNF表示法。与标准BNF的不同之处在于命名规则和指示重复和“局部”替代。尖括号<>仅用于规则的定义，帮助阅读以识别命名。E1/E2，表示E1或E2可选。(X (E1/E2) Y)表示，X E1 Y 或 X E2 Y可选。[E]表示E可选。<br>
&ensp;&ensp;&ensp;&ensp;&lt;n&gt;*&lt;m&gt;E，表示元素E重复n到m次，n默认为最小值0，m默认为最大值无穷大。 &lt;n&gt;#&lt;m&gt;E，含义同上，但每个元素之间使用1到多个逗号“，”分隔。&lt;n&gt;E，表示元素E重复n次。使用“;”表示注释。  
</p>  

<font size=3>3. 词法分析</font>  

3.1. 概述  
<p style="line-height:25px">
 &ensp;&ensp;&ensp;&ensp;<strong>消息由头字段和主体（可选）组成 ，主体由包含ASCII字符的行序列组成，它和头字段之间使用空行（一个仅有CRLF组成的行）分隔</strong>。  </p>
<font color=red><strong>3.1.1. 长头字段（头部字段折叠和展开）</strong></font> 
<p style="line-height:25px">
&ensp;&ensp;&ensp;&ensp;<strong>每个头字段可以被视为一个单独的逻辑行，由字段头(field-name)和字段体(field-body)组成，字段体可分成多行表示，即“折叠”，一般的规则是，只要有线性空白(1*([CRLF] LWSP-char))就可以插入至少一个CRLF+\<n\>LWSP-char（TAB或SPACE），对于地址字段，建议在地址之间的分隔逗号之后进行这种折叠</strong>。  <br>
&ensp;&ensp;&ensp;&ensp;<strong>将这种多行表示形式转换为单行表示形式的过程称为“展开”。展开是通过将CRLF+\<n\>LWSP-char作为与LWSP-char等价的字符（TAB或SPACE）来完成的</strong>。    <br>
&ensp;&ensp;&ensp;&ensp;举例----&ensp;：   <br>

&ensp;&ensp;&ensp;&ensp;折叠之前： TO: "Joe & J.Harvey" <x @ org>, JJV @ BBN  <br>
&ensp;&ensp;&ensp;&ensp;折叠之后： TO: "Joe  <br>
&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&   <br>
&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;J.Harvey" <x @ org>, JJV  <br>
&ensp;&ensp;&ensp;&ensp;@ BBN    <br>

&ensp;&ensp;&ensp;&ensp;虽然规范允许在任意线性空白处折叠断行，但推荐在特定空格分隔处，比如地址字段中的多个地址，折叠时尽量在各地址之间及逗号之后断行。  </p>
<font color=red><strong>3.1.2. 头部字段结构  </strong></font>
<p style="line-height:25px">
&ensp;&ensp;&ensp;&ensp;&ensp;<strong>头部字段（展开后）格式为：“field-name:[field-body]CRLF”，field-name由可打印ASCII字符（33~126，除冒号）组成，field-body由除CR和LF的任何ASCII组成。    </strong><br>
&ensp;&ensp;&ensp;&ensp;非文本（text）字段体被称为”结构化“字段体，反之为非结构化字段体，对于结构化字段体需要进一步结构化解析。  </p>
3.1.3. 非结构化字段体  
<p style="line-height:25px">
&ensp;&ensp;&ensp;&ensp;对于某些字段，如“Subject”和“Comments”，不需要构造，它们被简单地视为文本，就像在消息体中一样。折叠规则适用于这些字段，因此，当这些字段体占用几行时必须第一行以外的行至少缩进一个LWSP-char。</p>

3.1.4 结构化字段体
<p style="line-height:25px">
</p>
3.2 头部字段定义
<p style="line-height:25px">  
&ensp;&ensp;&ensp;&ensp;这些规则是消息头域的元语法定义，目的是为了在一行里方便的找到消息头的域, 并且把消息的各部分传递给更高级的解析器。
</p>
3.4 分类

3.4.1 引用
一些字符保留为特殊的翻译，为了让这些字符保持为不被翻译的数据就需要被转义，方法是在这些字符前面加反斜杠“\”。这种机制不是完全通用的，
3.4.2 空格

