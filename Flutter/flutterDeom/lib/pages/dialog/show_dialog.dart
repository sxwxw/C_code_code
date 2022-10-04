import 'dart:js';

import 'package:flutter/material.dart';
import 'package:flutterdeom/pages/people_demo.dart';
import 'package:fluttertoast/fluttertoast.dart';
import './dialog.dart';

class dialog extends StatefulWidget {
  const dialog({Key? key}) : super(key: key);

  @override
  _dialogState createState() => _dialogState();
}

class _dialogState extends State<dialog> {
  _AlerDialog() {
    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: Text('提示信息'),
          content: Text('确定删除吗'),
          actions: [
            TextButton(
              onPressed: () {
                Navigator.pop(context);
              },
              child: Text('取消'),
            ),
            TextButton(
              onPressed: () {
                Navigator.pop(context);
              },
              child: Text('确定'),
            ),
          ],
        );
      },
    );
  }

  _SimpleDialog() async {
    var result = await showDialog(
      context: context,
      builder: (context) {
        return SimpleDialog(
          title: Text('请选择'),
          children: [
            SimpleDialogOption(
              child: Text('optionA'),
              onPressed: () {
                Navigator.pop(context, 'A');
              },
            ),
            Divider(),
            SimpleDialogOption(
              child: Text('optionB'),
              onPressed: () {
                Navigator.pop(context, 'B');
              },
            ),
          ],
        );
      },
    );
    // ignore: avoid_print
    print(result);
  }

  _ModelBottomSheet() {
    showModalBottomSheet(
        context: context,
        builder: (context) {
          return SizedBox(
            height: 300,
            child: Column(
              children: [
                ListTile(
                  title: Text('A'),
                  onTap: () {},
                ),
                Divider(),
                ListTile(
                  title: Text('A'),
                  onTap: () {},
                ),
                Divider(),
                ListTile(
                  title: Text('A'),
                  onTap: () {},
                )
              ],
            ),
          );
        });
  }

  _toast() {
    Fluttertoast.showToast(
      msg: "This is Center Short Toast",
      toastLength: Toast.LENGTH_SHORT,
      gravity: ToastGravity.CENTER,
      timeInSecForIosWeb: 1,
      backgroundColor: Colors.red,
      textColor: Colors.white,
      fontSize: 16.0,
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('弹出层'),
      ),
      body: Column(
        children: [
          ElevatedButton(
            onPressed: _AlerDialog,
            child: Text('AlerDialog'),
          ),
          ElevatedButton(
            onPressed: _SimpleDialog,
            child: Text('SimpleDialog'),
          ),
          ElevatedButton(
            onPressed: _ModelBottomSheet,
            child: Text('ModelBottomSheet'),
          ),
          ElevatedButton(
            onPressed: _toast,
            child: Text('toast'),
          ),
          ElevatedButton(
            onPressed: () {},
            child: Text('自定义组件'),
          ),
        ],
      ),
    );
  }
}
