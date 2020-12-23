define(["require","exports","tslib","external/lodash","modules/clean/previews/constants","modules/clean/react/comments2/actions_adapters/basic","modules/clean/react/comments2/actions_adapters/spectrum_document","modules/clean/react/comments2/actions_adapters/timecode"],(function(e,a,t,o,n,r,d,s){"use strict";Object.defineProperty(a,"__esModule",{value:!0});var c=(o=t.__importStar(o)).noop,i={onInteractionWhileCollapsed:c,onClickTimeCode:c,onEditorFocused:c,onThreadActivated:c,onAllThreadsDeactivated:c,onThreadCreated:c,onThreadRepliedTo:c,onThreadMarkedAsRead:c,onThreadMarkedAsUnread:c,onThreadResolved:c,onThreadUnresolved:c,onCommentEdited:c,onCommentDeleted:c,onCommentDraftCancel:c,onMentionsQueryUpdated:c,onClickOlderInfo:c,onEditorStateChange:c};a.createActionsAdapter=function(e,a,o,c,l,m,p){var u,T=e.dispatch,v=e.previewType,_=e.stream,h=e.viewer,A=r.createBasicActionsAdapter(T,a,o,c,l,m,p,_,h);switch(v){case n.PreviewType.Audio:case n.PreviewType.Video:u=s.createTimecodeActionsAdapter(e.playerIntegrationEnabled,A);break;case n.PreviewType.SsrDoc:case n.PreviewType.Image:u=d.createSpectrumDocumentActionsAdapter(e,A);break;default:u={}}return t.__assign(t.__assign(t.__assign({},i),A),u)}}));
//# sourceMappingURL=index.min.js-vflHrS3Tm.map