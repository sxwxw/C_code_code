// button
// Page({
//   getPhoneNumber(event){
//     console.log(event);
//   },
//   getUserInfo(event){
//     console.log(event);
//   }
// })

// radio
// Page({
//     data:{
//         gender:""
//     },
//     change(e){
//         let gender = e.detail.value;
//         this.setData({
//             gender
//         })
//     }
// })

Page({
    data:{
        list:[
            {
                id:"0",
                name:"篮球",
                value:"lanqiu"
            },
            {
                id:"1",
                name:"羽毛球",
                value:"yumaoqiu"
            },
            {
                id:"1",
                name:"排球",
                value:"paiqiu"
            }
        ],
        checkedlist:[]
    },
    checkedname(e){
        const checkedlist = e.detail.value;
        this.setData({
            checkedlist
        })
    }
})