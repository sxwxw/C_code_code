import {request } from '../../request/index.js';
import regeneratorRuntime from '../../lib/runtime/runtime';
import {login} from '../../utils/asyncwx.js';
Page({
async  handuserinfo(e){
    // console.log(e);
    const {encryptedData,signature,iv,rawData} = e.detail;
    const {code} = await login();
    const loginpramise = {encryptedData,signature,iv,rawData,code};
    console.log(loginpramise);
    const res = await request({url:"/users/wxlogin",data:loginpramise,method:"post"});
    console.log(res);
  }
})