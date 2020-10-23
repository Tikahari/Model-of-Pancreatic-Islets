define("modules/clean/avatar/avatar_with_default",["require","exports","tslib","react","prop-types","modules/clean/avatar/photo_avatar","modules/clean/avatar/size","modules/clean/css"],(function(e,t,o,r,s,a,i,n){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),r=o.__importDefault(r),s=o.__importStar(s),n=o.__importStar(n);var l=(function(e){function t(){return null!==e&&e.apply(this,arguments)||this}return o.__extends(t,e),t.prototype.componentDidMount=function(){if(this.props.loadScooterCss&&n.require_css("/static/css/scooter/scooter-scoped-vfljL5ijS.css"),null==this.props.photoUrl&&null!=this.props.onLoad)return this.props.onLoad()},t.prototype.render=function(){if(null!=this.props.photoUrl){var e={alt:this.props.alt,dimension:this.props.dimension,onClick:this.props.onPhotoClick,photoUrl:this.props.photoUrl,optionalClass:this.props.optionalClass,shape:this.props.shape,onLoad:this.props.onLoad,onError:this.props.onError};return r.default.createElement(a.PhotoAvatar,o.__assign({},e))}return this.props.defaultAvatar},t.displayName="AvatarWithDefault",t.propTypes={alt:s.string,dimension:s.oneOf(i.VALID_AVATAR_DIMENSIONS).isRequired,defaultAvatar:s.element.isRequired,onPhotoClick:s.func,photoUrl:s.string,optionalClass:s.string,shape:s.oneOf(["CIRCLE","SQUARE"]).isRequired,onLoad:s.func,onError:s.func,loadScooterCss:s.bool},t.defaultProps={shape:"CIRCLE",loadScooterCss:!0},t})(r.default.Component);t.default=l})),define("modules/clean/avatar/initials_avatar",["require","exports","tslib","react","react-dom-factories","prop-types","modules/clean/avatar/size","modules/clean/avatar/style","modules/clean/avatar/style","modules/clean/css"],(function(e,t,o,r,s,a,i,n,l,p){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),r=o.__importDefault(r),s=o.__importDefault(s),a=o.__importStar(a),p=o.__importStar(p);var u=(function(e){function t(){return null!==e&&e.apply(this,arguments)||this}return o.__extends(t,e),t.prototype.render=function(){var e=this.props,t=(e.colorFromNameGenerator,e.name,o.__rest(e,["colorFromNameGenerator","name"]));return r.default.createElement(c,o.__assign({},t,{color:this.props.colorFromNameGenerator(this.props.name)}))},t.displayName="InitialsAvatarWithColorDerivedFromName",t.propTypes={name:a.string.isRequired,loadScooterCss:a.bool,colorFromNameGenerator:a.func},t.defaultProps={loadScooterCss:!0,colorFromNameGenerator:n.colorValueForAvatarName},t})(r.default.Component);t.InitialsAvatarWithColorDerivedFromName=u;var c=(function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.getContainerStyle=function(){var e={};return t.props.color&&(e.backgroundColor=t.props.color),e},t}return o.__extends(t,e),t.prototype.componentDidMount=function(){this.props.loadScooterCss&&p.require_css("/static/css/scooter/scooter-scoped-vfljL5ijS.css")},t.prototype.render=function(){var e=["c-avatar--no-img","c-avatar--"+this.props.shape.toLowerCase()];return null!=this.props.optionalClass&&e.push(this.props.optionalClass),null!=this.props.onClick&&this.props.alt?(e.push("u-unbutton"),s.default.button({className:l.getClassName(this.props.dimension,e),onClick:this.props.onClick,style:this.getContainerStyle()},s.default.span({"aria-hidden":!0},this.props.initials),s.default.span({className:"ax-visually-hidden"},this.props.alt))):s.default.div({className:l.getClassName(this.props.dimension,e),onClick:this.props.onClick,style:this.getContainerStyle()},null!=this.props.alt?[s.default.span({key:"initials","aria-hidden":!0},this.props.initials),s.default.span({key:"alt",className:"ax-visually-hidden"},this.props.alt)]:this.props.initials)},t.displayName="InitialsAvatar",t.propTypes={alt:a.string,dimension:a.oneOf(i.VALID_AVATAR_DIMENSIONS).isRequired,initials:a.string.isRequired,shape:a.oneOf(["CIRCLE","SQUARE"]).isRequired,color:a.string,onClick:a.func,optionalClass:a.string,loadScooterCss:a.bool},t.defaultProps={loadScooterCss:!0},t})(r.default.Component);t.InitialsAvatar=c})),define("modules/clean/avatar/photo_avatar",["require","exports","tslib","react","react-dom-factories","prop-types","modules/clean/avatar/size","modules/clean/avatar/style"],(function(e,t,o,r,s,a,i,n){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),r=o.__importDefault(r),s=o.__importDefault(s),a=o.__importStar(a);var l=(function(e){function t(){return null!==e&&e.apply(this,arguments)||this}return o.__extends(t,e),t.propTypes=function(){return{alt:a.string,dimension:a.oneOf(i.VALID_AVATAR_DIMENSIONS).isRequired,photoUrl:a.string.isRequired,onClick:a.func,optionalClass:a.string,shape:a.oneOf(["CIRCLE","SQUARE"]),onLoad:a.func,onError:a.func}},t.prototype.render=function(){var e=["c-avatar--"+this.props.shape.toLowerCase()];null!=this.props.optionalClass&&e.push(this.props.optionalClass);var t=s.default.img({alt:this.props.alt||"",src:this.props.photoUrl,width:this.props.dimension,height:this.props.dimension,onLoad:this.props.onLoad,onError:this.props.onError});return null!=this.props.onClick&&this.props.alt?(e.push("u-unbutton"),s.default.button({className:n.getClassName(this.props.dimension,e),onClick:this.props.onClick},t)):s.default.div({className:n.getClassName(this.props.dimension,e),onClick:this.props.onClick},t)},t.defaultProps={shape:"CIRCLE"},t})(r.default.Component);t.PhotoAvatar=l})),define("modules/clean/avatar/size",["require","exports"],(function(e,t){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var o={XSMALL:16,SMALL:24,MEDIUM:32,LARGE:48,XLARGE:64};t.AVATAR_DIMENSION_BY_SIZE=o;var r=(function(){var e=[];for(var t in o)e.push(o[t]);return e})();t.VALID_AVATAR_DIMENSIONS=r})),define("modules/clean/avatar/style",["require","exports","tslib","classnames","modules/clean/accessibility/utils"],(function(e,t,o,r,s){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),r=o.__importDefault(r);var a={16:"c-avatar--xs",24:"c-avatar--s",32:"c-avatar--m",48:"c-avatar--l",64:"c-avatar--xl"},i=function(e,t){void 0===e&&(e=""),void 0===t&&(t=s.accessibleColorPalette);for(var o=5381*e.length,r=0;r<e.length;)o=e.charCodeAt(r)+((o<<6)+(o<<16)-o),r++;return t[(o=Math.abs(o))%t.length]};t.colorValueForAvatarName=i;t.brandedColorValueFromAvatarName=function(e){return void 0===e&&(e=""),i(e,s.accessibleBrandedColorPalette)};t.getClassName=function(e,t){void 0===e&&(e=32),void 0===t&&(t=[]);var o=["c-avatar",a[e]];return t=t.concat(o),r.default.apply(this,t)}})),define("modules/clean/cookie_check",["require","exports","tslib","jquery","modules/core/cookies","modules/core/i18n","modules/core/notify"],(function(e,t,o,r,s,a,i){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),r=o.__importDefault(r),t.initialize_module=function(e){if(!s.Cookies.are_enabled())return r.default((function(){return i.Notify.error(a.intl.formatMessage({id:"mO3cx4",defaultMessage:"Please enable browser-cookies to use the Dropbox website."}))}))}}));
//# sourceMappingURL=pkg-coreui-with-i18n.min.js-vflqkYMZm.map