import 'package:flutter/material.dart';
import 'package:flutterdeom/pages/news.dart';
import 'package:flutterdeom/pages/shop.dart';
import 'package:flutterdeom/pages/appbar.dart';

class home extends StatefulWidget {
  const home({Key? key}) : super(key: key);

  @override
  _homeState createState() => _homeState();
}

class _homeState extends State<home> {
  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        ElevatedButton(
          onPressed: () {
            Navigator.pushNamed(
              context,
              '/shop',
              arguments: {'pid': 345},
            );
          },
          child: const Text('跳转到商品页面'),
        ),
        ElevatedButton(
          onPressed: () {
            Navigator.pushNamed(
              context,
              '/news',
              arguments: {
                'id': 123,
                'content': '海南湖北',
              },
            );
          },
          child: const Text('跳转到消息页面并传值'),
        ),
        ElevatedButton(
          onPressed: () {
            Navigator.pushNamed(
              context,
              '/bar',
            );
          },
          child: const Text('跳转到bar'),
        ),
        ElevatedButton(
          onPressed: () {
            Navigator.pushNamed(
              context,
              '/bartwo',
            );
          },
          child: const Text('跳转到bartwo'),
        ),
        ElevatedButton(
          onPressed: () {
            Navigator.pushNamed(
              context,
              '/farm',
            );
          },
          child: const Text('跳转到farm'),
        ),
        ElevatedButton(
          onPressed: () {
            Navigator.pushNamed(
              context,
              '/check',
            );
          },
          child: const Text('跳转到check'),
        ),
        ElevatedButton(
          onPressed: () {
            Navigator.pushNamed(
              context,
              '/people',
            );
          },
          child: const Text('跳转到people'),
        ),
        ElevatedButton(
          onPressed: () {
            Navigator.pushNamed(
              context,
              '/times',
            );
          },
          child: const Text('跳转到times'),
        ),
        ElevatedButton(
          onPressed: () {
            Navigator.pushNamed(
              context,
              '/timetwo',
            );
          },
          child: const Text('跳转到timetwo'),
        ),
        ElevatedButton(
          onPressed: () {
            Navigator.pushNamed(
              context,
              '/swiper',
            );
          },
          child: const Text('跳转到swiper'),
        ),
        ElevatedButton(
          onPressed: () {
            Navigator.pushNamed(
              context,
              '/dialog',
            );
          },
          child: const Text('跳转到dialog'),
        ),
      ],
    );
  }
}
