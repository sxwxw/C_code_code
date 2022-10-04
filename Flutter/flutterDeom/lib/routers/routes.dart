import 'package:flutter/material.dart';
import 'package:flutterdeom/pages/tabs/tabs_main.dart';
import 'package:flutterdeom/pages/news.dart';
import 'package:flutterdeom/pages/shop.dart';
import 'package:flutterdeom/pages/appbar.dart';
import 'package:flutterdeom/pages/appbar_two.dart';
import 'package:flutterdeom/pages/user.dart';
import 'package:flutterdeom/pages/farm.dart';
import 'package:flutterdeom/pages/check_box.dart';
import 'package:flutterdeom/pages/people_demo.dart';
import 'package:flutterdeom/pages/time_one.dart';
import 'package:flutterdeom/pages/time_two.dart';
import 'package:flutterdeom/pages/swiper.dart';
import 'package:flutterdeom/pages/dialog/show_dialog.dart';

final routes = {
  '/': (context, {arguments}) => Tabs(),
  '/news': (context, {arguments}) => news(arguments: arguments),
  '/shop': (context, {arguments}) => shop(arguments: arguments),
  '/bar': (context) => appbar(),
  '/bartwo': (context) => AppBarTwo(),
  '/user': (context) => UserInfo(),
  '/farm': (context) => farm(),
  '/check': (context) => checkall(),
  '/people': (context) => people(),
  '/times': (context) => times(),
  '/timetwo': (context) => timeTwo(),
  '/swiper': (context) => swiper(),
  '/dialog': (context) => dialog(),
};

// 配置路由传参
// ignore: prefer_function_declarations_over_variables
var onGenerateRoute = (RouteSettings settings) {
  final String? name = settings.name;
  final Function pageContentBuilder = routes[name] as Function;
  if (pageContentBuilder != null) {
    if (settings.arguments != null) {
      final Route route = MaterialPageRoute(
        builder: (context) =>
            pageContentBuilder(context, arguments: settings.arguments),
      );
      return route;
    } else {
      final Route route = MaterialPageRoute(
        builder: (context) => pageContentBuilder(context),
      );
      return route;
    }
  }
};
