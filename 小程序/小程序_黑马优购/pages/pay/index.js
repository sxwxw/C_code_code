// pages/cart/index.js
import {getSetting,chooseAddress,openSetting} from "../../utils/asyncwx.js"
import regeneratorRuntime from '../../lib/runtime/runtime';

Page({
  data: {
    address:{},
    cart:[],
    totalprice:0,
    totalnum:0
  },
  // 页面刷新
  onShow(){
    const address = wx.getStorageSync('address');
    let cart = wx.getStorageSync('cart')||[];
    cart = cart.filter(v=>v.checked);
    this.setData({
      address
    })
    let totalprice = 0;
    let totalnum = 0;
    cart.forEach(v => {
        totalprice+=v.goods_price*v.num;
        totalnum+=v.num;
    });
    this.setData({
      cart,totalprice,totalnum,address
    })
  },
  handpays(e){
    // console.log(e);
    const token = wx.setStorageSync('token')
    if(!token)
    {
      wx.navigateTo({
        url: '../../pages/auth/index'
      })
      return ;
    }
    console.log("有token值");
  }
})