//表面贴图的追加效果
/*思考 积雪效果:
	积雪等级 雪的颜色 以及积雪的方向
	通过计算原图的点在世界坐标中的法线方向与积雪方向的点积 如果大于
	设定的积雪等级的阀值的话表示这个方向与积雪方向是抑制的 其上是可以积雪的 显示雪的颜色

*/
Shader "Custom/Diffuse Texture"{
	Properties{
		_MainTex ("Base (RGB)",2D) = "White" {}
		_Bump ("Bump",2D) ="bump"{}
		_Snow("Snow Level",Range(0,1) )=0
		_SnowColor ("Snow Color",Color) = (1.0,1.0,1.0,1.0)
		//提一下方向 默认值是0.1.0 表示我们希望雪是垂直落下的
		_SnowDirection ("Snow Direction",Vector) = (0,1,0)
	}
	SubShader{
		Tags {"Rendertype"="Opaque"}
		LOD 200

		CGPROGRAM
		#progma surface surf CustomDiffuse
		//对输入的变量进行声明
		sampler2D _MainTex;
		sampler2D _Bump;
		float _Snow;
		float4 _SnowColor;
		float4 _SnowDirection;
		//改变Input的内容
		struct Input{
			float2 uv_MainTex;
			float2 uv_Bump;
			//新加入
			float3 worldNormal;INTERNAL_DATA
		};
		void surf (Input IN,inout SurfaceOutput o){

			half4 c=tex2D(_MainTex,IN.uv_MainTex);
			o.Normal = UnpackNormal(tex2D(_Bump,In.uv_Bump));

			//对雪的方向和输入点的世界法线方向进行点积
			//WorldNormalVector通过输入的点及这个点的法线值，来计算它在世界坐标中的方向
			/*
			当Snow取最小值0时，这个函数将返回1，
			而Snow取最大值时，返回-1。这样我们就可以通过设定Snow的值来控制积雪的阈值，
			要是积雪等级Snow是0时，不等式左侧不可能大于右侧，因此完全没有积雪；
			相反要是_Snow取最大值1时，由于左侧必定大于-1，
			所以全模型积雪。而随着取中间值的变化，积雪的情况便会有所不同。*/
			if(dot(WorldNormalVector(IN,o.Normal),_SnowDirection.xyz) > lerp(1,-1,_Snow)){
				o.Albedo = _SnowColor.rgb;
			}else{
				o.Albedo=c.rgb;
			}

			o.Alpha=c.a;
		}
		inline float4 LightingCustomDiffuse (SurfaceOutput s,fixed3 lightDir,fixed atten){
			float4 disLight=max(0,dot(s.Normal,lightDir));
			float4 col;
			col.rgb=s.Albedo * _LightColor0.rgb *(difLight * atten * 2);
			col.a=s.Alpha;
			return col;
		}
		ENDCG
	}
	FallBack "Diffuse"
}
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
/*
关于lerp函数：
 0 print(Mathf.Lerp(0.0f, 100.0f, 0.0f).ToString());    
  10   print(Mathf.Lerp(0.0f, 100.0f, 0.1f).ToString());     
    20     print(Mathf.Lerp(0.0f, 100.0f, 0.2f).ToString()); 
      30           print(Mathf.Lerp(0.0f, 100.0f, 0.3f).ToString());     
        40             print(Mathf.Lerp(0.0f, 100.0f, 0.4f).ToString());     
          50               print(Mathf.Lerp(0.0f, 100.0f, 0.5f).ToString()); 
            60                     print(Mathf.Lerp(0.0f, 100.0f, 0.6f).ToString());     
            70    print(Mathf.Lerp(0.0f, 100.0f, 0.7f).ToString());      
                80   print(Mathf.Lerp(0.0f, 100.0f, 0.8f).ToString());       
                  90   print(Mathf.Lerp(0.0f, 100.0f, 0.9f).ToString());       
                    100   print(Mathf.Lerp(0.0f, 100.0f, 1.0f).ToString());
这个实验是在0到100之间插值，插入什么值，取决于第3个参数，从打印结果可看出
*/

