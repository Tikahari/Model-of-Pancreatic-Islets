define(["require","exports","tslib","react","modules/clean/react/css","modules/clean/react/extensions/extensions_menu_component_v2","react-redux","modules/clean/react/extensions/data/store","modules/clean/react/extensions/client"],(function(e,t,n,s,r,a,i,o,u){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var c=(function(e){function t(t){var s=e.call(this,t)||this;return s.getFeatureFlags=function(){return n.__awaiter(s,void 0,void 0,(function(){var e,t,s,r;return n.__generator(this,(function(n){switch(n.label){case 0:return e=this.props,t=e.file,s=e.user,[4,u.getExtensionsClient().getActionsForFile(t,s)];case 1:return n.sent(),r=u.getExtensionsClient().getFeatureFlags(),this.setState({featureFlags:r}),[2]}}))}))},s.state={featureFlags:{}},s.reduxStore=o.initializeStore(t.user,[]),s.getFeatureFlags(),s}return n.__extends(t,e),t.prototype.UNSAFE_componentWillReceiveProps=function(e){this.getFeatureFlags()},t.prototype.render=function(){return s.default.createElement(i.Provider,{store:this.reduxStore},s.default.createElement("div",{className:this.props.className},s.default.createElement(a.ExtensionsMenuV2,n.__assign({},this.props))))},t})((s=n.__importDefault(s)).default.Component);t.UnconnectedMenu=r.requireCssWithComponent(c,["/static/css/app_actions/index-vflHsvf3d.css"])}));
//# sourceMappingURL=unconnected_menu_wrapper.min.js-vfl0jSseM.map