//光照模型
Shader "Custom/Normal Mapping"{
	Properties{
		_MainTx ("Base (RGB)",2D) = "white"{}
		
		//1 声明并加入一个显示名称为Bump的贴图
		_Bump ("Bump",2D) = "bump" {}
	
	}
	SubShader{
		Tags {"RenderType"="Opaque" }
		LOD 200
		
		CGPROGRAM
		//这里以前是Lambert光照模型 现在换成了CustomDIffuse
		#progma surface surf CustomDiffuse
		
		sampler2D _MainTx;
		
		//2 为了能在CG程序中使用这张贴图 必须加入一个sample
		sampler2D _Bump;
		
		struct Input{
			float2 uv_MainTex;
			
			//3 获得Bump的uv信息作为输入
			float2 uv_Bump;
		
		};
		//自己设定的光照模型 注释解释在最后
		inline float4 LightingCustomDiffuse (SurfaceOutput s,fixed3 lightDir,fixed atten){
			float4 disLight=max(0,dot(s.Normal,lightDir));
			float4 col;
			col.rgb=s.Albedo * _LightColor0.rgb *(difLight * atten * 2);
			col.a=s.Alpha;
			return col;
		}

		//将模型改亮一点
		inline float4 LightingCustomDiffuse(SurfaceOutput s,fixed3 lightDir,fixed atten){
			float difLight=dot(s.Normal,lightDir);
			float hLambert=difLight*0.5+0.5;
			float4 col;
			col.rgb=s.Albedo * _LightColor0.rgb *(hLambert * atten * 2);
			col.a=s.Alpha;
			return col;
		}

		void surf(Input In,inout SurfaceOutput o){
		
		half4 c = tex2D (_MainTx,In.uv_MainTex);
		//4 从法线图中提取法线信息 并将其赋值与相应点的输出的Normal属性
		//。UnpackNormal是定义在UnityCG.cginc文件中的方法，这个文件中包含了一系列常用的CG变量以及方法。
		//UnpackNormal接受一个fixed4的输入，并将其转换为所对应的法线值（fixed3）。在解包得到这个值之后，将其赋给输出的Normal，就可以参与到光线运算中完成接下来的渲染工作了。
		o.Normal=UnpackNormal(tex2D(_Bump,IN.uv_Bump));
		
		o.Albedo=c.rgb;
		o.Alpha = c.a;
		}
		ENDCG
	}
	FallBack "Diffuse"
}
/*shader中对于方法的名称有着比较严格的约定，
想要创建一个光照模型，首先要做的是按照规则声明一个光照计算的函数名字，
即Lighting<Your Chosen Name>。对于我们的光照模型CustomDiffuse，
其计算函数的名称自然就是LightingCustomDiffuse了。
光照模型的计算是在surf方法的表面颜色之后，根据输入的光照条件来对原来的颜色在这种光照下的表现进行计算，最后输出新的颜色值给渲染单元完成在屏幕的绘制。
该方法实现的LightingCustomDiffuse所实现与Unity内建中的LightingLamber是完全一样的
SurfaceOutput s 是经过表面计算函数surf处理后的输出
fixed3 lightDir是光线的方向 
fixed atten表示光的衰减系数
在计算光照的代码中，我们先将输入的s的法线值（在Normal mapping中的话这个值已经是法线图中的对应量了）和输入光线进行点积（dot函数是CG中内置的数学函数，希望你还记得，可以参考这里）。点积的结果在-1至1之间，这个值越大表示法线与光线间夹角越小，这个点也就应该越亮。
之后使用max来将这个系数结果限制在0到1之间，是为了避免负数情况的存在而导致最终计算的颜色变为负数，输出一团黑，一般来说这是我们不愿意看到的。接下来我们将surf输出的颜色与光线的颜色_LightColor0.rgb（由Unity根据场景中的光源得到的，它在Lighting.cginc中有声明）进行乘积，然后再与刚才计算的光强系数和输入的衰减系数相乘，最后得到在这个光线下的颜色输出（关于difLight * atten * 2中为什么有个乘2，这是一个历史遗留问题，主要是为了进行一些光强补偿，可以参见这里的讨论）

*/
/*
struct SurfaceOutput {
    half3 Albedo;     //像素的颜色
    half3 Normal;     //像素的法向值
    half3 Emission;   //像素的发散颜色
    half Specular;    //像素的镜面高光
    half Gloss;       //像素的发光强度
    half Alpha;       //像素的透明度
};
*/