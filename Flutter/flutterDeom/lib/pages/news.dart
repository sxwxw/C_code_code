import 'package:flutter/material.dart';
// 无状态页面

class news extends StatelessWidget {
  final arguments;
  const news({this.arguments});
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      floatingActionButton: FloatingActionButton(
        child: Text('返回'),
        onPressed: () {},
      ),
      appBar: AppBar(
        title: Text('消息'),
      ),
      body: Text('${arguments != null ? arguments['content'] : '空'}'),
    );
  }
}
