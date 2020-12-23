define(["require","exports","tslib","react","classnames","prop-types","comments2/components/comment_editor/comment_utils","comments2/components/comment_editor/comment_editor","comments2/components/comment_editor/components/post_bar","comments2/components/sticker_component/sticker_component","comments2/components/comment_stream/comment_stream_post_bar"],(function(e,t,n,o,s,r,a,c,i,l,m){"use strict";function p(e,t){var s=t.localization.intl,r=e.stickerPacks,a=e.signals.postSticker;if(e.isEmpty&&r&&r.length>0)return o.createElement(m.InlineControls,null,o.createElement(l.StickerComponent,Object.assign({},{stickerPacks:r,onStickerSelected:a})));if(e.isEmpty)return null;var c=e.disabled,p=e.postEnabled,d=n.__rest(e,["disabled","postEnabled"]);return o.createElement(i.PostBar,Object.assign({},d,{postEnabled:p&&!c,postLabel:s.formatMessage({id:"7Oex9C",defaultMessage:"Post"}),cancelLabel:s.formatMessage({id:"xuJw2w",defaultMessage:"Cancel"})}))}Object.defineProperty(t,"__esModule",{value:!0}),o=n.__importStar(o),s=n.__importDefault(s),r=n.__importStar(r),a=n.__importStar(a),t.ThreadEditorPostBar=p,p.contextTypes={localization:r.object};var d=(function(e){function t(){var t=e.apply(this,arguments)||this;return t.state={content:a.createEmptyContent()},t.clear=function(){t.setState({content:a.createEmptyContent()})},t.onPost=function(e,n){t.props.disabled||(t.clear(),t.props.onPost(e,n))},t.onCancel=function(){t.clear(),t.props.onCancel()},t.renderPostBar=function(e){return o.createElement(p,Object.assign({},e,{disabled:t.props.disabled}))},t}return n.__extends(t,e),t.prototype.render=function(){var e=this.intl,t=this.props,n=t.author,r=t.shouldFocus,a=t.mentionsMatches,i=t.onEditorStateChange,l=t.onMentionsQueryUpdated,m=t.onFocus,p=void 0===m?function(){return{}}:m,d=t.onBlur,u=void 0===d?function(){return{}}:d,f=t.stickerPacks,_=this.state.content,b=s.default({"sc-thread-editor":!0});return o.createElement("div",{className:b},o.createElement(c.CommentEditor,{a11yEditorLabel:e.formatMessage({id:"1s2pn+",defaultMessage:"Reply"}),author:n,shouldFocus:r,content:_,mentionsMatches:a,onEditorStateChange:i,onMentionsQueryUpdated:l,onCancel:this.onCancel,onPost:this.onPost,placeholder:e.formatMessage({id:"1s2pn+",defaultMessage:"Reply"}),postSignalComponent:this.renderPostBar,onFocus:p,onBlur:u,stickerPacks:f}))},Object.defineProperty(t.prototype,"intl",{get:function(){return this.context.localization.intl},enumerable:!0,configurable:!0}),t})(o.PureComponent);t.ThreadEditor=d,d.contextTypes={localization:r.object}}));
//# sourceMappingURL=thread_editor.min.js-vflMcCaB9.map