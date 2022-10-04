// 引入放送请求的方法
import {request } from '../../request/index.js';
import regeneratorRuntime from '../../lib/runtime/runtime';
Page({
  data: {
    tabs:[
      {
        id:0,
        value:"综合",
        isActive:true
      },
      {
        id:1,
        value:"销量",
        isActive:false
      }, 
      {
        id:2,
        value:"价格",
        isActive:false
      }

    ],
    goodslist:[]
  },
  totalpages:1,
  // 接口要的参数
  QueryParams:{
    query:'',
    cid:'',
    pagenum:1,
    pagesize:10
  },
  onLoad: function (options) {
    // console.log(options);
    // console.log(this.QueryParams);
    this.QueryParams.cid=options.cid;
    this.getgoodslist();
    // console.log(this.goodslist);
  },
  // 获取商品列表数据
  async getgoodslist(){
    const res = await request({url:"/goods/search",data:this.QueryParams});
    // console.log(res);
    const total = res.total;
    // this.totalpages总页数
    // total 总条数
    this.totalpages =Math.ceil(total/this.QueryParams.pagesize);
    // console.log(this.totalpages);
    // console.log(this.data.goodslist);
    this.setData({
      // 拼接数组
      goodslist:[...this.data.goodslist,...res.goods]
    })
    // 关闭下拉刷新提示
    wx.stopPullDownRefresh();
  },
  // 点击事件绑定
  handtabsitem(e){
    // console.log(e);
    const {index} = e.detail;
    // console.log(this.data);
    const {tabs}=this.data;
    // console.log(tabs);
    tabs.forEach((v,i) => {
      i===index?v.isActive=true:v.isActive=false
    });
    this.setData({
      tabs
    })
  },
  // 上拉触底事件
  onReachBottom(){
    if(this.QueryParams.pagenum>=this.totalpages)
    {
      wx.showToast({
        title: '没有下一页数据了',
        icon: ''
      })
    }
    else{
      this.QueryParams.pagenum++;
      this.getgoodslist();
    }
  },
  // 下拉刷新事件
  onPullDownRefresh(){
    this.setData({
      goodslist:[]
    }),
    this.QueryParams.pagenum=1;
    this.getgoodslist();
  }
})